#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Task *task = new Task(&a);

    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));

    task->run();

    return a.exec();
}
