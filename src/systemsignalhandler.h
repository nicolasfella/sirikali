/*
 *
 *  Copyright (c) 2018
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HANDLE_SYSTEM_SIGNAL_H
#define HANDLE_SYSTEM_SIGNAL_H

#include <QObject>
#include <functional>
#include <vector>

class systemSignalHandler{
public:
	enum class signal{ HUP = 1,INT = 2,QUIT = 3,TERM = 15,WINDOWS_END_SESSION } ;
	void setHandle( std::function< void( systemSignalHandler::signal ) > function ) ;
	void addSignal( systemSignalHandler::signal SIG ) ;
	systemSignalHandler( QObject * parent ) ;
private:
	static void signalHandle( int SIG ) ;
	struct manager{
		manager( systemSignalHandler::signal sig ) ;
		systemSignalHandler::signal signal ;
		int sockpair[ 2 ] ;
		int read() const;
		int write() const;
	};
	static std::function< void( systemSignalHandler::signal ) > m_function ;
	static std::vector< manager > m_signals ;
	static QObject * m_parent ;
};

#endif
