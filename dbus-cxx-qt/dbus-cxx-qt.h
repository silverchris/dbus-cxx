/***************************************************************************
 *   Copyright (C) 2020 by Robert Middleton                                *
 *   robert.middleton@rm5248.com                                           *
 *                                                                         *
 *   This file is part of the dbus-cxx library.                            *
 *                                                                         *
 *   The dbus-cxx library is free software; you can redistribute it and/or *
 *   modify it under the terms of the GNU General Public License           *
 *   version 3 as published by the Free Software Foundation.               *
 *                                                                         *
 *   The dbus-cxx library is distributed in the hope that it will be       *
 *   useful, but WITHOUT ANY WARRANTY; without even the implied warranty   *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU   *
 *   General Public License for more details.                              *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this software. If not see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/
#ifndef DBUS_CXX_QT_H
#define DBUS_CXX_QT_H

#include <dbus-cxx/threaddispatcher.h>
#include <dbus-cxx/connection.h>
#include <dbus-cxx/dbus-cxx-config.h>
#include <memory>
#include <QObject>

namespace DBus {
namespace Qt {

class QtThreadDispatcher : public QObject,
        public DBus::ThreadDispatcher {
    Q_OBJECT

private:
    QtThreadDispatcher();

public:
    ~QtThreadDispatcher();

    void add_message( std::shared_ptr<ObjectPathHandler> object, std::shared_ptr<const CallMessage> message );
    void add_signal_proxy( std::shared_ptr<signal_proxy_base> handler );
    bool remove_signal_proxy( std::shared_ptr<signal_proxy_base> handler );
    void add_signal( std::shared_ptr<const SignalMessage> message );

    static std::shared_ptr<QtThreadDispatcher> create();

private:
    class priv_data;

    DBUS_CXX_PROPAGATE_CONST(std::unique_ptr<priv_data>) m_priv;
};

} /* namespace Qt */
} /* namespace DBus */

#endif /* DBUS_CXX_QT_H */