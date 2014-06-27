// Copyright (c) 2011-2014 The VirtaCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VIRTACOINADDRESSVALIDATOR_H
#define VIRTACOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class VirtaCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit VirtaCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** VirtaCoin address widget validator, checks for a valid virtacoin address.
 */
class VirtaCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit VirtaCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // VIRTACOINADDRESSVALIDATOR_H
