//
//  DomainServerUpgrader.h
//  domain-server/src
//
//  Created by Kalila L. on May 28th, 2021.
//  Copyright 2021 Vircadia contributors.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#pragma once

#ifndef vircadia_DomainServerUpgrader_h
#define vircadia_DomainServerUpgrader_h

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <HTTPManager.h>

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

class DomainServerUpgrader : public QObject
{
    Q_OBJECT
    public:
    explicit DomainServerUpgrader(QUrl releaseRepositoryURL, QObject* parent = 0);
        virtual ~DomainServerUpgrader();

    signals:
        void downloaded(QByteArray downloadedData);
        void error(QString errorString);
        void finished();

    private slots:
        void repositoryRequestFinished(QNetworkReply* pReply);
        private:
        QNetworkAccessManager m_WebCtrl;
};


#endif // vircadia_DomainServerUpgrader_h
