#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    ui->menuWidget->setCurrentIndex(0);
}

mainmenu::~mainmenu()
{
    db.close();
    delete ui;
}

//****************** login function and database declaration (menuWidget Index 0)

void mainmenu::on_loginB_clicked()
{
    db.setHostName("bugtrackerdb.ciqvuqcuauuy.us-east-2.rds.amazonaws.com");
    db.setPort(3306);
    db.setDatabaseName("bugtrackerdb");
    QString user = ui->userName->text();
    QString pass = ui->userPassword->text();
    db.setUserName(user);
    db.setPassword(pass);
    db.open();
    ui->menuWidget->setCurrentIndex(1);
    ui->queryWidget->setCurrentIndex(0);
}

//****************** queryWidget and logout function (menuWidget Index 1)

void mainmenu::on_logOut_clicked()
{
    db.close();
    ui->menuWidget->setCurrentIndex(0);
}

// (queryWidget Index 0)
void mainmenu::on_viewAll_clicked()
{
    ui->queryWidget->setCurrentIndex(0);

    viewAllModel->setQuery("SELECT * FROM bugs", db);
    viewAllModel->removeColumns(0, 1);

    ui->tableViewObj->setModel(viewAllModel);
}

// (queryWidget Index 1)
void mainmenu::on_viewIss_clicked()
{
    ui->queryWidget->setCurrentIndex(1);
}

void mainmenu::on_searchBtn_clicked()
{
    searchModel->setQuery("SELECT * FROM bugs WHERE dev LIKE '%" + ui->searchQuery->text() + "%' OR bug LIKE '%" + ui->searchQuery->text() + "%'");

    if(searchModel->lastError().isValid())
    {
        searchModel->removeColumns(0, 1);
        ui->searchView->setModel(searchModel);
    }
    else
    {
        searchModel->setQuery("Select * FROM bugs");
        ui->searchView->setModel(searchModel);
    }

}

// (queryWidget Index 2)
void mainmenu::on_bugDesc_textChanged()
{
    int length = ui->bugDesc->toPlainText().length();

    if (length > 255)
    {
        QString strLimit = ui->bugDesc->toPlainText();
        strLimit.chop(length-255);
        ui->bugDesc->setPlainText(strLimit);
        QTextCursor cursor(ui->bugDesc->textCursor());
        cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->bugDesc->setTextCursor(cursor);
    }
}

void mainmenu::on_addIss_clicked()
{
    ui->queryWidget->setCurrentIndex(2);
    ui->bugDate->setDate(QDate::currentDate());

}

void mainmenu::on_addIssueBtn_clicked()
{
    QDate selDate = ui->bugDate->date();
    QString dateString = selDate.toString("yyyy-MM-dd");

    addIssueQ->prepare("INSERT INTO bugs (date, bug, bugdetail, dev, status, priority) "
                       "VALUES (:date, :bug, :bugdetail, :dev, :status, :priority)");

    addIssueQ->bindValue(":date", dateString);
    addIssueQ->bindValue(":bug", ui->bugSum->text());
    addIssueQ->bindValue(":bugdetail", ui->bugDesc->toPlainText());
    addIssueQ->bindValue(":dev", ui->devName->text());
    addIssueQ->bindValue(":status", ui->status->itemText(ui->status->currentIndex()));
    addIssueQ->bindValue(":priority", ui->priority->itemText(ui->priority->currentIndex()));

    addIssueQ->exec();

    updateD m;
    m.exec();

    clearAddForm();
}

void mainmenu::clearAddForm()
{
    ui->bugDate->setDate(QDate::currentDate());
    ui->bugSum->clear();
    ui->bugDesc->clear();
    ui->devName->clear();
    ui->status->clear();
    ui->priority->clear();
}
