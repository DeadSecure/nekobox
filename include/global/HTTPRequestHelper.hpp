#pragma once

#include <QObject>
#include <functional>

namespace NekoGui_network {
    struct NekoHTTPResponse {
        QString error;
        QByteArray data;
        QList<QPair<QByteArray, QByteArray>> header;
    };

    struct DownloadProgressReport
    {
        QString fileName;
        qint64 downloadedSize;
        qint64 totalSize;
    };

    class NetworkRequestHelper : QObject {
        Q_OBJECT

        explicit NetworkRequestHelper(QObject *parent) : QObject(parent){};

        ~NetworkRequestHelper() override = default;
        ;

    public:
        static NekoHTTPResponse HttpGet(const QString &url);

        static QString GetHeader(const QList<QPair<QByteArray, QByteArray>> &header, const QString &name);

        static QString DownloadAsset(const QString &url, const QString &fileName);
    };
} // namespace NekoGui_network

using namespace NekoGui_network;
