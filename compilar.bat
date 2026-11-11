@echo off
chcp 65001 >nul
gcc controle_financeiro.c -o Financeiro.exe
if errorlevel 1 pause
Financeiro.exe
pause