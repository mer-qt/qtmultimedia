/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QABSTRACTMEDIAOBJECT_P_H
#define QABSTRACTMEDIAOBJECT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qbytearray.h>
#include <QtCore/qset.h>
#include <QtCore/qtimer.h>

#include "qmediaobject.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Multimedia)


class QMetaDataReaderControl;
class QMediaAvailabilityControl;

#define Q_DECLARE_NON_CONST_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    friend class Class;


class QMediaObjectPrivate
{
    Q_DECLARE_PUBLIC(QMediaObject)

public:
    QMediaObjectPrivate(): service(0), metaDataControl(0), availabilityControl(0), notifyTimer(0), q_ptr(0) {}
    virtual ~QMediaObjectPrivate() {}

    void _q_notify();
    void _q_availabilityChanged();

    QMediaService *service;
    QMetaDataReaderControl *metaDataControl;
    QMediaAvailabilityControl *availabilityControl;

    QTimer* notifyTimer;
    QSet<int> notifyProperties;

    QMediaObject *q_ptr;
};

QT_END_NAMESPACE

QT_END_HEADER


#endif
