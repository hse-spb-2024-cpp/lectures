# Ubuntu
Все действия ниже выполняются из консоли:

1. Проверьте, что у вас действительно Ubuntu 22.04: команда `cat /etc/lsb-release` должна вывести <code>Ubuntu 22.04.3 LTS</code>, цифра 3 может быть другой.
2. Обновите всю систему до последней версии: `sudo apt update && sudo apt upgrade`. Теперь версия должны быть `Ubuntu 22.04.3 LTS`.
3. Дальше установите необходимый набор пакетов (вы можете склеить эти команды в одну большую `sudo apt instal a b c d e ...`, чтобы сразу скачать все пакеты):
    ```bash
    sudo apt install g++-12  # Компилятор GCC 12 со стандартной библиотекой libstdc++
    sudo apt install valgrind  # Инструмент Valgrind
    # Среды разработки ставятся по-разному, тут инструкции нет.
    sudo apt install clang-format-15 clang-tidy-15  # Инструменты от LLVM
    sudo apt install cppcheck  # Cppcheck
    sudo apt install git  # Консольный клиент для git; bash и timeout уже стоят
    # Python уже стоит (команда python3)
    sudo apt install cmake make  # CMake и Make
    ```
4. При желании установите больше компиляторов и стандартных библиотек:

    ```bash
    sudo apt install clang-15  # Компилятор Clang 14
    sudo apt install libc++-15-dev libc++abi-15-dev  # Стандартная библиотека libc++
    ```
5. При желании также установите компилятор Intel C++ Compiler (не путать с Intel DPC++ Compiler).
   Он ставится как часть Intel oneAPI Base Toolkit:
   1. Добавьте новый репозиторий [вот так](https://www.intel.com/content/www/us/en/docs/oneapi/installation-guide-linux/2023-0/apt.html#PRE-INSTALLATION-STEPS) ("Pre-installation Steps", шаг 3).
      Если не грузится — это санкции, попробуйте через VPN.
   2. Установите командой `sudo apt update && sudo apt install intel-oneapi-compiler-dpcpp-cpp-and-cpp-classic`
   3. Для запуска настройте окружение в текущей консоли командой `. /opt/intel/oneapi/setvars.sh` и запускайте компилятор командой `icc`.
   4. При первом запуске может возникнуть предупреждение об устаревании `icc`, его можно игнорировать (TODO).
6. Для конкретных домашних заданий установите:
    ```
    sudo apt install libboost-all-dev  # Boost, скомпилированный для работы с libstdc++
    sudo apt install netcat-openbsd  # Утилита netcat, вызывается командой `nc`
    ```
7. При желании можете установите виртуальную машину, а потом установить внутрь неё Windows. Рекомендуется VirtualBox: <code>sudo apt install virtualbox</code>.
   Ссылка на образ Windows есть в общей инструкции, как и инструкции по её настройке.

При работе из консоли всегда используйте команды с суффиксом версии: `g++-12` вместо `g++`, `clang++-15`, `clang-format-15`, `clang-tidy-15`.
Пакеты и команды без суффикса, вроде `g++`, могут относиться к старым версиям.

В частности, вам нужно корректно настроить вашу среду разработки и консольный CMake (при помощи параметра вроде `-DCMAKE_CXX_COMPILER=g++-12`).

## Актуальные версии инструментов
```bash
g++-12 --version  # g++-12 (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
clang++-15 --version  # Ubuntu clang version 15.0.7
valgrind --version  # valgrind-3.18.1
clang-format-15 --version  # Ubuntu clang-format version 15.0.7
clang-tidy-15 --version  # Ubuntu LLVM version 15.0.7
cppcheck --version  # Cppcheck 2.7
git --version  # git version 2.34.1
cmake --version  # cmake version 3.22.1
make --version  # GNU Make 4.3
nc -h  # OpenBSD netcat (Debian patchlevel 1.218-4ubuntu1)
```

# Другие дистрибутивы Linux
Вы можете либо поставить виртуальную машину с Ubuntu, либо сделать Docker-контейнер (TODO) на основе образа Ubuntu 22.04.
