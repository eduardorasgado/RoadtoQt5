#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Declaring the list
    QList<QString> stringlist;

    // putting data inside the list
    stringlist.push_back("Hello");
    stringlist.append("Friend");
    stringlist.append("!");

    stringlist << "HELLO" << "FRIEND" << "!!";

    // accessing to elements in QList
    qDebug() << "string[1]: "<< stringlist[1] << "\n";

    for(auto& w : stringlist){
        qDebug() << w;
    }

    qDebug() << "Number of elements in qlist: " << stringlist.count();

    for(int i = 0; i < stringlist.size(); ++i)
    {
        qDebug() << "element " << QString::number(i)
                 << ": " << stringlist.at(i);
    }
    return a.exec();
}
