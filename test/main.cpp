#define VIN_ENABLE_ASSERT

#include <vinbase.hpp>
#include <assert.hpp>
#include <bitset.hpp>

#include <iostream>

void TestBitset() {
	Vin::BitSet<512> bitset1{};
	Vin::BitSet<512> bitset2{};

	VIN_ASSERT_NOMSG(sizeof(bitset1) == 64);

	bitset1.SetBit(1);
	bitset1.SetBit(52);

	VIN_ASSERT_NOMSG(bitset1.GetBit(1));
	VIN_ASSERT_NOMSG(bitset1.GetBit(52));
	VIN_ASSERT_NOMSG(!bitset1.GetBit(51));

	bitset1.SetBit(51);
	bitset1.ClearBit(52);

	VIN_ASSERT_NOMSG(bitset1.GetBit(1));
	VIN_ASSERT_NOMSG(!bitset1.GetBit(52));
	VIN_ASSERT_NOMSG(bitset1.GetBit(51));

	VIN_ASSERT_NOMSG(bitset1 != bitset2);
	
	VIN_ASSERT_NOMSG(bitset1);
	VIN_ASSERT_NOMSG(!bitset2);
	VIN_ASSERT_NOMSG(!(bitset1 & bitset2));

	bitset1.Clear();

	VIN_ASSERT_NOMSG(!bitset1.GetBit(1));
	VIN_ASSERT_NOMSG(!bitset1.GetBit(52));
	VIN_ASSERT_NOMSG(!bitset1.GetBit(51));

	VIN_ASSERT_NOMSG(bitset1 == bitset2);
}

int main() {
	TestBitset();
}
