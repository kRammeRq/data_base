# data_base
Простая база данных
Программа может обрабатывать набор команд:
Add date event — добавить в базу данных пару (date, event);
Print — вывести всё содержимое базы данных;
Find condition — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию condition;
Del condition — удалить из базы все записи, которые удовлетворяют условию condition;
Last date — вывести запись с последним событием, случившимся не позже данной даты.

Условия в командах Find и Del накладывают определённые ограничения на даты и события, например:

Find date < 2017-11-06 — найти все события, которые случились раньше 6 ноября 2017 года;

Del event != "holiday" — удалить из базы все события, кроме «holiday»;

Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event" — найти всё события «sport event», случившиеся в первой половине 2017 года;

Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event") — удалить из базы все события «holiday» и «sport event», случившиеся до 2017 года.

В командах обоих типов условия могут быть пустыми: под такое условие попадают все события.
