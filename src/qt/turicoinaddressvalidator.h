// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TURICOIN_QT_TURICOINADDRESSVALIDATOR_H
#define TURICOIN_QT_TURICOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TuriCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TuriCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** TuriCoin address widget validator, checks for a valid turicoin address.
 */
class TuriCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TuriCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // TURICOIN_QT_TURICOINADDRESSVALIDATOR_H
