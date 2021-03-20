@echo off

@REM указать переменную окружения 
@REM установить туда библиотеку и заголовки

setx GAS_CORE_HOME %cd%
echo "gas library registered"
set GAS_CORE_HOME

@REM echo %userprofile%\documents
