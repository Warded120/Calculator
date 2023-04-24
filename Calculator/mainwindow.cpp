#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <sstream>
#include <algorithm>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isThere(QString line, QChar el)
{
    for(auto el_line : line)
        if(el_line == el)
            return true;
    return false;
}

//global vars---------
QVector<double> numbers;
double temp_num;
QVector<char> operations;
QString str_num = "";
QString expression = "";
stringstream convert;
bool is_result_action = false;
//--------------------

void MainWindow::on_one_clicked()
{
    ui->messagebox->setText("");

    str_num += '1';
    expression += '1';

    ui->infobox->setText(expression);
}

void MainWindow::on_two_clicked()
{
    ui->messagebox->setText("");

    str_num += '2';
    expression += '2';

    ui->infobox->setText(expression);
}

void MainWindow::on_three_clicked()
{
    ui->messagebox->setText("");

    str_num += '3';
    expression += '3';

    ui->infobox->setText(expression);
}

void MainWindow::on_four_clicked()
{
    ui->messagebox->setText("");

    str_num += '4';
    expression += '4';

    ui->infobox->setText(expression);
}

void MainWindow::on_five_clicked()
{
    ui->messagebox->setText("");

    str_num += '5';
    expression += '5';

    ui->infobox->setText(expression);
}

void MainWindow::on_six_clicked()
{
    ui->messagebox->setText("");

    str_num += '6';
    expression += '6';

    ui->infobox->setText(expression);
}

void MainWindow::on_seven_clicked()
{
    ui->messagebox->setText("");

    str_num += '7';
    expression += '7';

    ui->infobox->setText(expression);
}

void MainWindow::on_eight_clicked()
{
    ui->messagebox->setText("");

    str_num += '8';
    expression += '8';

    ui->infobox->setText(expression);
}

void MainWindow::on_nine_clicked()
{
    ui->messagebox->setText("");

    str_num += '9';
    expression += '9';

    ui->infobox->setText(expression);
}

void MainWindow::on_zero_clicked()
{
    ui->messagebox->setText("");

    str_num += '0';
    expression += '0';

    ui->infobox->setText(expression);
}

void MainWindow::on_plus_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("No two arithmetic operations in a row");
        return;
    }

    try
    {
        if(! is_result_action)
        {
            convert.clear();
            convert.str("");
            convert<<str_num.toStdString();
            str_num = "";
            convert>>temp_num;

            numbers.append(temp_num);
        }
        else
            is_result_action = false;


        expression += '+';
        operations.append('+');
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    ui->infobox->setText(expression);
}

void MainWindow::on_minus_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("No two arithmetic operations in a row");
        return;
    }

    try
    {
        if(! is_result_action)
        {
            convert.clear();
            convert.str("");
            convert<<str_num.toStdString();
            str_num = "";
            convert>>temp_num;

            numbers.append(temp_num);
        }
        else
            is_result_action = false;

        expression += '-';
        operations.append('-');
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    ui->infobox->setText(expression);
}

void MainWindow::on_mul_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("No two arithmetic operations in a row");
        return;
    }

    try
    {
        if(! is_result_action)
        {
            convert.clear();
            convert.str("");
            convert<<str_num.toStdString();
            str_num = "";
            convert>>temp_num;

            numbers.append(temp_num);
        }
        else
            is_result_action = false;

        expression += '*';
        operations.append('*');
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    ui->infobox->setText(expression);
}

void MainWindow::on_div_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("No two arithmetic operations in a row");
        return;
    }

    try
    {
        if(! is_result_action)
        {
            convert.clear();
            convert.str("");
            convert<<str_num.toStdString();
            str_num = "";
            convert>>temp_num;

            numbers.append(temp_num);
        }
        else
            is_result_action = false;

        expression += '/';
        operations.append('/');
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    ui->infobox->setText(expression);
}

void MainWindow::on_rem_div_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("No two arithmetic operations in a row");
        return;
    }

    try
    {
        if(! is_result_action)
        {
            convert.clear();
            convert.str("");
            convert<<str_num.toStdString();
            str_num = "";
            convert>>temp_num;

            numbers.append(temp_num);

        }
        else
            is_result_action = false;

        expression += '%';
        operations.append('%');
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    ui->infobox->setText(expression);
}

void MainWindow::on_point_clicked()
{
    string temp = str_num.toStdString();
    auto it = ::find(temp.begin(), temp.end(), '.');
    if(it == temp.end())
    {
        str_num += '.';
        expression += '.';
        ui->infobox->setText(expression);
    }
    else
        ui->messagebox->setText("No two floating points in a number");
}

void MainWindow::on_equals_clicked()
{
    ui->messagebox->setText("");

    if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("Finish the expression before calculating it");
        return;
    }

    try
    {
        convert.clear();
        convert.str("");
        convert<<str_num.toStdString();
        str_num = "";
        convert>>temp_num;

        numbers.append(temp_num);
    }
    catch(exception &e)
    {
        ui->messagebox->setText(e.what());
    }

    QVector<QVector<char>> ops_priority = {{'*', '/'}, {'%'}, {'+', '-'}};

    for (auto op_group : ops_priority)
    {
        auto it = find_first_of(operations.begin(), operations.end(), op_group.begin(), op_group.end());
        while (it != operations.end())
        {
            int index = it - operations.begin();
            switch (*it)
            {
            case '*':
                numbers[index] *= numbers[index+1];
                break;
            case '/':
                if (numbers[index+1] == 0)
                {
                    ui->messagebox->setText("Division by zero");
                    return;
                }
                numbers[index] /= numbers[index+1];
                break;
            case '%':
                if (numbers[index+1] == 0)
                {
                    ui->messagebox->setText("Modulo by zero.");
                    return;
                }
                numbers[index] = std::fmod(numbers[index], numbers[index+1]);
                break;
            case '+':
                numbers[index] += numbers[index+1];
                break;
            case '-':
                numbers[index] -= numbers[index+1];
                break;
            }
            numbers.erase(numbers.begin() + index + 1);
            operations.erase(it);
            it = find_first_of(operations.begin(), operations.end(), op_group.begin(), op_group.end());
        }
    }

    //    double temp = numbers[0];
    //    numbers.clear();
    //    numbers.append(temp);

    expression = QString("%1").arg(numbers[0]);
    operations.clear();

    is_result_action = true;

    ui->infobox->setText(expression);
}

void MainWindow::on_eraseline_clicked()
{
    ui->messagebox->setText("");

    expression = "";
    str_num = "";
    operations.clear();
    numbers.clear();

    is_result_action = false;

    ui->infobox->setText(expression);
}

void MainWindow::on_backspace_clicked()
{
    ui->messagebox->setText("");

    if(expression == "")
    {
        ui->messagebox->setText("Input is empty");
    }
    else if(isThere("-+*/%", expression[expression.length() - 1]))
    {
        ui->messagebox->setText("Deleting arithmetic operation is forbidden");

    }
    else
    {
        str_num.erase(str_num.end() - 1);
        expression.erase(expression.end() - 1);
        ui->infobox->setText(expression);
    }
}

void MainWindow::on_exit_clicked()
{
    QCoreApplication::quit();
}

