#include"hashing/qcurlp81.hpp"
#include"encoding/qb1t6.hpp"
#undef NDEBUG
#include <assert.h>



using namespace qencoding::qb1t6;

using namespace qhashing;

int main(int argc, char** argv)
{
    auto digest=QByteArray::fromHex("511bc81dde11180838c562c82bb35f3223f46061ebde4a955c27b3f489cf1e03");
    auto nonce=QByteArray::fromHex("5ee6aaaaaaaaaaaa");
    const auto treZeros=QByteArray(3,0);
    auto curl_input=get_Trits_from_Bytes(digest);
    curl_input.append(get_Trits_from_Bytes(nonce));
    curl_input.append(treZeros);

    auto ternary=get_Trytes_from_Trits(curl_input);
    assert(ternary==QByteArray("9C9AYYBATZQAXAH9BBVYQDYYPBDXNDWBHAO9ODPDFZTZTCAWKCLADXO9PWEYCAC9MCAZVXVXVXVXVXVX9"));
    auto curlp= curlP(curl_input);
    auto hash=curlp.get_hash();
    assert(get_Trytes_from_Trits(hash)==QByteArray("DJCAGKILZPLXNXWFTNXFLCHRFVUHHMTPFIOFKQXMGIKITSEVWECMQOKCFXDIIHK9YVHGQICAIVEVDJ999"));
    assert(curlp.get_TrailingZeros()==9);

	return 0;
}
