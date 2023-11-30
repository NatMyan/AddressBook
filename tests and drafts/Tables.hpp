/*#ifndef TABS_HPP
#define TABS_HPP

#include <QTabWidget>
#include <QTableWidget>
#include <QVector>

class Tables : public QTabWidget {
    Q_OBJECT

    public:
        Tables(QWidget *parent = nullptr, QVector<QTableWidget*> tables);
        void operator=(const Tables& other);

    public:
        QVector<QTableWidget*> getTables();
        void addTable (QTableWidget* table);
        
    private:
        QVector<QTableWidget*> tables_;
};

#endif // TABS_HPP*/