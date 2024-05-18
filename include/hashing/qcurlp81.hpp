#pragma once
/**
 * https://github.com/iotaledger/tips/blob/main/tips/TIP-0012/tip-0012.md
 *
 **/

#include <QByteArray>
namespace qhashing
{
class curlP : public QByteArray
{
  public:
    using QByteArray::QByteArray;
    curlP(const QByteArray &trits);
    QByteArray get_hash(void) const;
    quint8 get_TrailingZeros(void) const;

  private:
    void transform(void);
    static const int TruthTable[];
};
} // namespace qhashing
