#pragma once

#include <QString>
#include <QUuid>
#include <QtWidgets>

class Note
{
    QString m_name;
    QString m_date;
    QString m_text;
    QUuid m_uuid;
public:
    Note(QString m_name, QString m_date, QString m_text, QUuid m_uuid);
    QString getName() const;
    void setName(QString m_name);
    QString getDate() const;
    void setDate(QString m_date);
    QString getText() const;
    void setText(QString m_text);
    QUuid getUuid() const;
    void setUuid(QUuid m_uuid);
};

bool operator ==(const Note& lhs, const Note& rhs);
