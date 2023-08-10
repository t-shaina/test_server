#ifndef JSON_CREATOR_H
#define JSON_CREATOR_H


#include<QStringList>
#include<QJsonObject>
#include<QJsonArray>
#include<QString>

class Json_creator
{

public:
    Json_creator(QString data);
    static QJsonArray creating_directors_or_genre_array(QString data);
    static QJsonObject creating_row_object(QString title, QString genre, QString year, QString rating, QString status);
    static QJsonArray creating_rows_array();
    static QJsonArray creating_row_array();
    static QJsonArray creating_new_old_array();
    QJsonObject get_json_data();
    ~Json_creator();
private:
    QJsonObject json_data;
};

#endif // JSON_CREATOR_H
