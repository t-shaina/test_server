#include <QCoreApplication>
#include<QTcpServer>
#include "test_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test_server* server=new Test_server(&a);


    return a.exec();
}
