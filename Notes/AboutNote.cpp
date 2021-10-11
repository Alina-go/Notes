#include "AboutNote.h"

Note::Note(QString name, QString date, QString text, QUuid uuid) {
    m_name = name;
    m_date = date;
    m_text = text;
    m_uuid = uuid;
}

QString Note::getName() const{
    return m_name;
}

void Note::setName(QString name) {
    m_name = name;
}

QString Note::getDate() const{
    return m_date;
}

void Note::setDate(QString date) {
    m_date = date;
}

QString Note::getText() const{
    return m_text;
}

void Note::setText(QString text) {
    m_text = text;
}

QUuid Note::getUuid() const {
    return m_uuid;
}

void Note::setUuid(QUuid uuid) {
    m_uuid = uuid;
}

bool operator ==(const Note& lhs, const Note& rhs) {
    if (lhs.getName() == rhs.getName()) {
        if (lhs.getDate() == rhs.getDate()) {
            if (lhs.getText() == rhs.getText()) {
                if (lhs.getUuid() == rhs.getUuid())
                    return true;
            }
        }
    }
    return false;
}
