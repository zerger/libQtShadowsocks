/*
 * chacha.h - the header file of ChaCha class
 *
 * This class is partly ported from Botan::ChaCha
 *
 * Copyright (C) 2014-2015 Symeon Huang <hzwhuang@gmail.com>
 *
 * This file is part of the libQtShadowsocks.
 *
 * libQtShadowsocks is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libQtShadowsocks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef CHACHA_H
#define CHACHA_H

#include <QObject>
#include <QVector>

namespace QSS {

class ChaCha : public QObject
{
    Q_OBJECT
public:
    /*
     * Key length must be 32 (16 is dropped)
     * IV length must be 8
     */
    explicit ChaCha(const QByteArray &_key, const QByteArray &_iv, QObject *parent = 0);

public slots:
    //encrypt (or decrypt, same process for ChaCha algorithm) a byte array.
    QByteArray update(const QByteArray &input);

private:
    QVector<quint32> m_state;
    QVector<unsigned char> m_buffer;
    size_t m_position;

    void chacha();

    inline void chacha_xor(unsigned char *ks, const unsigned char *in, unsigned char *out, size_t length)
    {
        unsigned char *end_ks = ks + length;
        do {
            *out = *in ^ *ks;
            ++out; ++in; ++ks;
        } while (ks < end_ks);
    }
};

}

#endif // CHACHA_H
