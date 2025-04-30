::Display the age getting birthyear as user input.

@echo OFF

::get the user input about the birth year
set /p birthyear=Enter your birthyear :

::calculates the age using the current year from %date%  
::current date wed 30/04/2025
::year start from 10th position(start from 0) to 4 places(so we write %date:~10,4%)
:: we use /a command when we do calculation
set /a age=%date:~ 10,4% -%birthyear%

::displays the age according to the birth year
echo age:%age%

::Keeps the window open until the user presses a key
pause