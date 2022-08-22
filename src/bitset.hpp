#pragma once

#include "vinbase.hpp"

#include <cstring>

namespace Vin {

	template<usize size>
	class BitSet {
	public:
		inline byte* GetData() {
			return data;
		}

		inline byte GetBit(usize idx) {
			return (data[idx / 8] & (1 << (idx % 8))) > 0;
		}
		inline void SetBit(usize idx) {
			data[idx / 8] |= (1 << (idx % 8));
		}
		inline void ClearBit(usize idx) {
			data[idx / 8] &= ~(1 << (idx % 8));
		}
		inline void Clear() {
			memset(data, 0, length);
		}

		operator bool() const {
			for (usize i = 0; i < length; ++i)
				if (data[i]) return true;
			return false;
		}

		inline friend bool operator==(const BitSet<size>& lhs, const BitSet<size>& rhs) {
			for (usize i = 0; i < length; ++i)
				if (lhs.data[i] != rhs.data[i])
					return false;
			return true;
		}
		inline friend bool operator!=(const BitSet<size>& lhs, const BitSet<size>& rhs) {
			return !(lhs == rhs);
		}

		BitSet<size>& operator&=(const BitSet<size>& rhs) {
			for (usize i = 0; i < length; ++i)
				data[i] &= rhs.data[i];
			return *this;
		}

		friend BitSet<size> operator&(BitSet<size> lhs, const BitSet<size>& rhs) {
			lhs &= rhs;
			return lhs;
		}
	private:
		static constexpr usize length = (size - 1) / 8 + 1;
		byte data[length];
	};

}
