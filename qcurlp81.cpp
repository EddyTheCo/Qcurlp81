#include"hashing/qcurlp81.hpp"
#include<iostream>
namespace qhashing{

#define HASH_LENGTH 243
#define STATE_LENGTH 3 * HASH_LENGTH
#define NUMBER_OF_ROUNDS 81

	const int curlP::TruthTable[]= { 1, 0, -1, 2, 1, -1, 0, 2, -1, 1, 0 };

	curlP::curlP(const QByteArray & trits):QByteArray(STATE_LENGTH,0)
	{
		replace(0,trits.size(),trits);
		transform();
	}

	void curlP::transform(void)
	{
		std::size_t scratchpadIndex      = 0;
		std::size_t prev_scratchpadIndex = 0;

		for (auto round = 0; round < NUMBER_OF_ROUNDS; round++)
		{
			auto scratchpad=QByteArray(*this);
			for(auto i=0;i<size();i++)
			{
				prev_scratchpadIndex = scratchpadIndex;
				scratchpadIndex += (scratchpadIndex < 365 ? 364 : -365);
				(*this)[i] = TruthTable[scratchpad[prev_scratchpadIndex] + (scratchpad[scratchpadIndex] << 2) + 5];
			}
		}

	}
	QByteArray curlP::get_hash(void)const
	{
		return QByteArray(this->data(),243);
	}
	quint8 curlP::get_TrailingZeros(void) const
	{

		quint8 var=0;
		for(auto i=242;i>=0;i--)
		{
			if(at(i)!=0)
			{
				return var;
			}
			else
			{
				var++;
			}
		}
		return size();
	}
}
