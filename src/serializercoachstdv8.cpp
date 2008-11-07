// -*-c++-*-

/***************************************************************************
                            serializercoachstdv8.cpp
               Class for serializing data to std v8 offline coaches
                             -------------------
    begin                : 27-JAN-2003
    copyright            : (C) 2003 by The RoboCup Soccer Server
                           Maintenance Group.
    email                : sserver-admin@lists.sourceforge.net
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU LGPL as published by the Free Software  *
 *   Foundation; either version 2 of the License, or (at your option) any  *
 *   later version.                                                        *
 *                                                                         *
 ***************************************************************************/

#include "serializercoachstdv8.h"
#include "clangmsg.h"
#include "object.h"
#include "player.h"

namespace rcss {

SerializerCoachStdv8::SerializerCoachStdv8( const SerializerCommon & common )
    : SerializerCoachStdv7( common )
{

}


SerializerCoachStdv8::~SerializerCoachStdv8()
{

}

const
SerializerCoachStdv8 *
SerializerCoachStdv8::instance()
{
    rcss::SerializerCommon::Creator cre;
    if ( ! rcss::SerializerCommon::factory().getCreator( cre, 8 ) )
    {
        return NULL;
    }

    static SerializerCoachStdv8 ser( cre() );
    return &ser;
}

void
SerializerCoachStdv8::serializeVisualObject( std::ostream & strm,
                                             const std::string & name,
                                             const PVector & pos,
                                             const PVector & vel,
                                             const int body,
                                             const int neck,
                                             const bool tackling ) const
{
    strm << " (" << name
         << ' ' << pos.x << ' ' << pos.y
         << ' ' << vel.x << ' ' << vel.y
         << ' ' << body
         << ' ' << neck;
    if ( tackling )
    {
        strm << " t";
    }
    strm << ')';
}

void
SerializerCoachStdv8::serializeVisualObject( std::ostream & strm,
                                             const std::string & name,
                                             const PVector & pos,
                                             const PVector & vel,
                                             const int body,
                                             const int neck,
                                             const int point_dir,
                                             const bool tackling ) const
{
    strm << " (" << name
         << ' ' << pos.x << ' ' << pos.y
         << ' ' << vel.x << ' ' << vel.y
         << ' ' << body
         << ' ' << neck
         << ' ' << point_dir;
    if ( tackling )
    {
        strm << " t";
    }
    strm << ')';
}


void
SerializerCoachStdv8::serializeVisualPlayer( std::ostream & strm,
                                             const Player & player,
                                             const std::string & name,
                                             const PVector & pos,
                                             const PVector & vel,
                                             const int body,
                                             const int neck ) const
{
    strm << " (" << name
         << ' ' << pos.x << ' ' << pos.y
         << ' ' << vel.x << ' ' << vel.y
         << ' ' << body
         << ' ' << neck;
    if ( player.isTackling() )
    {
        strm << " t";
    }
    strm << ')';
}

void
SerializerCoachStdv8::serializeVisualPlayer( std::ostream & strm,
                                             const Player & player,
                                             const std::string & name,
                                             const PVector & pos,
                                             const PVector & vel,
                                             const int body,
                                             const int neck,
                                             const int point_dir ) const
{
    strm << " (" << name
         << ' ' << pos.x << ' ' << pos.y
         << ' ' << vel.x << ' ' << vel.y
         << ' ' << body
         << ' ' << neck
         << ' ' << point_dir;
    if ( player.isTackling() )
    {
        strm << " t";
    }
    strm << ')';
}


namespace {
const
SerializerCoach *
create()
{
    return SerializerCoachStdv8::instance();
}

RegHolder v8 = SerializerCoach::factory().autoReg( &create, 8 );
RegHolder v9 = SerializerCoach::factory().autoReg( &create, 9 );
RegHolder v10 = SerializerCoach::factory().autoReg( &create, 10 );
RegHolder v11 = SerializerCoach::factory().autoReg( &create, 11 );
RegHolder v12 = SerializerCoach::factory().autoReg( &create, 12 );
}

}
