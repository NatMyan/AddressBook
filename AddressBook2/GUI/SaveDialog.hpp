#ifndef SAVE_DIALOG_HPP
#define SAVE_DIALOG_HPP

#include <QFileDialog>
#include <QString>

class SaveDialog : public QFileDialog {
    Q_OBJECT

    public:
        SaveDialog(QWidget *parent = nullptr);
        QString getSelectedFilePath() const;

    public slots:
        void save();

    private:
        QString selectedFilePath;
};

#endif // SAVE_DIALOG_HPP
