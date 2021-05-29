//
//  DomainServerUpgrader.cpp
//  domain-server/src
//
//  Created by Kalila L. on May 28th, 2021.
//  Copyright 2021 Vircadia contributors.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "DomainServerUpgrader.h"

DomainServerUpgrader::DomainServerUpgrader(QUrl releaseRepositoryURL, QObject* parent) : QObject(parent)
{
    connect(
        &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (repositoryRequestFinished(QNetworkReply*))
    );

    QNetworkRequest request(releaseRepositoryURL);
    m_WebCtrl.get(request);
}

DomainServerUpgrader::~DomainServerUpgrader() { }

void DomainServerUpgrader::repositoryRequestFinished(QNetworkReply* pReply) {
    QByteArray downloadedData = pReply->readAll();

    if (pReply->error() == QNetworkReply::NoError) {
        emit downloaded(downloadedData);
    } else {
        emit error(pReply->errorString());
    }

    emit finished();
    pReply->deleteLater();
}
