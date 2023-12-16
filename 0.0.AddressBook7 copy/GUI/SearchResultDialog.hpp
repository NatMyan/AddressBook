#ifndef SEARCH_RESULT_DIALOG_HPP
#define SEARCH_RESULT_DIALOG_HPP

#include "../Data/Contact.hpp"

#include <QDialog>
#include <QVector>

class SearchResultDialog : public QDialog {
    public:
        SearchResultDialog(QVector<Contact> qVec, QWidget* parent = nullptr);

    public:
        void showSearchResultDialog();

    private:
        QVector<Contact> qVec_;
};

#endif // SEARCH_RESULT_DIALOG_HPP