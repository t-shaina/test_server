#include "json_creator.h"
#include <QString>
Json_creator::Json_creator(QString data)

{

    switch (data.toInt()) {
    case 0:
        json_data["RequestCode"]="0";
        json_data["ErrorCode"]="0";
        json_data["Email"]="tanya";
        json_data["Name"]="name";
        json_data["Rows"]=Json_creator::creating_rows_array();
        break;
    case 1:
        json_data["RequestCode"]="1";
        json_data["ErrorCode"]="0";       
        json_data["Rows"]=Json_creator::creating_row_array();
        break;
    case 2:
        json_data["RequestCode"]="2";
        json_data["ErrorCode"]="0";
        json_data["Rows"]=Json_creator::creating_row_object("Барби", "Комедия", "2023", "4", "Просмотрено");
        break;
    case 3:
        json_data["RequestCode"]="3";
        json_data["ErrorCode"]="0";
        json_data["Rows"]=Json_creator::creating_row_array();

        break;
    case 4:
        json_data["RequestCode"]="4";
        json_data["ErrorCode"]="0";
        json_data["Name"]="tanya";
        json_data["Email"]="tanya";
        break;
    case 5:
        json_data["RequestCode"]="5";
        json_data["ErrorCode"]="0";
        json_data["Rows"]=Json_creator::creating_rows_array();
        break;
    case 6:
        json_data["RequestCode"]="6";
        json_data["ErrorCode"]="0";
        json_data["Row_new"]=Json_creator::creating_row_object("Шрек", "Боевик", "2023", "4", "Просмотрено");
        json_data["Row_old"]=Json_creator::creating_row_object("Пианист", "Драма", "1999", "5", "Собираюсь посмотреть");

        break;
    default:
        break;
    }

}
Json_creator::~Json_creator(){
    qDebug()<<"in ~Json_creator";
}
QJsonObject Json_creator::get_json_data(){
    return this->json_data;
}
QJsonArray Json_creator::creating_rows_array(){
    QJsonArray rows;
    rows.append(Json_creator::creating_row_object("Пианист", "Драма", "1999", "5", "Собираюсь посмотреть"));
    rows.append(Json_creator::creating_row_object("Гадкий Я", "Мультфильм", "1999", "1", "Просмотрено"));
    rows.append(Json_creator::creating_row_object("Барби", "Комедия", "2023", "4", "Просмотрено"));
    return rows;
}
QJsonArray Json_creator::creating_row_array(){
    QJsonArray rows;
    rows.append(Json_creator::creating_row_object("Пианист", "Драма", "1999", "5", "Собираюсь посмотреть"));
    return rows;
}
QJsonArray Json_creator::creating_directors_or_genre_array(QString data){
    QJsonArray data_array;
    int length=0;

        data_array.push_back(data);

    return data_array;
}
QJsonObject Json_creator::creating_row_object(QString title, QString genre, QString year, QString rating, QString status){
    QJsonObject json_row_data;
    QJsonArray directors_array;
    directors_array.push_back("Михалковский");
    directors_array.push_back("Тарантино");
    directors_array.push_back("Тарковский");
    QJsonArray  genres_array;
    genres_array.push_back("Ужасы");
    genres_array.push_back("Комедия");
    genres_array.push_back("Мелодрама");
    genres_array.push_back("Драма");
    json_row_data["Title"]=title;
    json_row_data["Directors"]=directors_array;
    json_row_data["Genres"]=genres_array;
    json_row_data["Year"]=year;
    json_row_data["Rating"]=rating;
    json_row_data["Status"]=status;
    return json_row_data;
}
QJsonArray Json_creator::creating_new_old_array(){
    QJsonObject Row_new=Json_creator::creating_row_object("Шрек", "Драма", "1999", "5", "Собираюсь посмотреть");
    QJsonObject Row_old=Json_creator::creating_row_object("Пианист", "Драма", "1999", "5", "Собираюсь посмотреть");
    QJsonArray Rows;
    Rows.append(Row_new);
    Rows.append(Row_old);
    return Rows;
}
