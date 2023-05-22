# digital_signal_processing
Практическое задание в НИЦ ЭТУ.

## Постановка задачи:

1.	Реализовать программный модуль фильтрации входящего сигнала на основе скользящего окна;
2.	Найти временной ряд отклонений (дисперсий) и построить их функцию распределения;
3.	Построить автокорреляционную функцию временного ряда:
 -	Реализовать при помощи стандартного способа (кольцевого смещения);
 -	При помощи БПФ;

## Общие требования по выполнению:
1. Код должен быть написан понятно и аккуратно, с соблюдением табуляции и прочих элементов написания, без лишних элементов и функций, не имеющих отношения к функционалу тестового задания, снабжен понятными комментариями.
2. Чистота и оформление кода — не менее важный фактор. Код должен быть написан в едином стиле (желательно в рекомендуемом для конкретного языка). Также к чистоте относятся отсутствие копипаста и дублирования логики.
3. Исходные коды должны быть в Git. Желательно делать частые информативные коммиты, активно использовать ветки.
4. Должна быть инструкция по сборке и разворачиванию, а также должен быть описан порядок развертывания и запуска проекта в среде разработки (включая настройку БД, дамп схемы БД, настройку сервера приложения для запуска и т.д.)
5. Сервисы (серверная часть) должны быть максимально покрыты модульными тестами
6. Интерфейс должен отвечать требованиям usability

## Результат
Проект необходимо собрать при помощи Make. <br>
При запуске пользователю предлагается выбрать генератор сигнала - синусоида или синусоида с шумом. Для выбранного генератора вводятся параметры. <br>
Далее необходимо выбрать метод фильтрации (единственный вариант - метод скользящего среднего). <br>
Далее выбирается метод вычисления автокорреляционной функции.
<br>

![изображение](https://user-images.githubusercontent.com/99137907/234003664-4f4e31ed-6435-4dc5-9cf1-c67e81f62b78.png)

<br>
Если количество измерений больше 16, результат выводится в файл

По графикам можно убедиться в правильности выполнения программы: 
<br>
![изображение](https://user-images.githubusercontent.com/99137907/234002809-baedc0ef-e510-4a74-90a1-ac7d475796b0.png)
<br>
![изображение](https://github.com/u5ele55/digital_signal_processing/assets/99137907/22a485ce-25fa-480b-8561-2cb34cd9a397)
<br>