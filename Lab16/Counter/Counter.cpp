// ======================================================================
//  Counter.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 4.8 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2012 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook     : http://www.facebook.com/mschlee
//  Twitter      : http://twitter.com/Max_Schlee
//  2Look.me     : http://2look.me/NW100003
//  Xing         : http://www.xing.com/profile/Max_Schlee
//  VKontakte.ru : http://www.vkontakte.ru/max.schlee
// ======================================================================

#include "Counter.h"

// ----------------------------------------------------------------------
Counter::Counter() : QObject()
                   , m_nValue(0)
{
}

// ----------------------------------------------------------------------
void Counter::slotInc()
{
    emit counterChanged(++m_nValue);

    if (m_nValue == 5) {
        emit goodbye();
    }
}
