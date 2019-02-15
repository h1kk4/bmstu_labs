## Laboratory work VIII

Данная лабораторная работа посвещена изучению средств пакетирования на примере **CPack**

```ShellSession
$ open https://cmake.org/Wiki/CMake:CPackPackageGenerators
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Задаем переменные окружения
```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ alias edit=<nano|vi|vim|subl>
$ alias gsed=sed # for *-nix system
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
Копирование репозитория 7 лабораторной 
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 projects/lab08
$ cd projects/lab08
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```
Редактирование CMakeLists.txt, устанавливая новые версии MAJOR, TWEAK, PATCH, MINOR
```ShellSession
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION \
\${PRINT_VERSION_MAJOR}.\${PRINT_VERSION_MINOR}.\${PRINT_VERSION_PATCH}.\${PRINT_VERSION_TWEAK})
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_TWEAK 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_PATCH 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MINOR 1)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MAJOR 0)
' CMakeLists.txt
```
Создание файлов DESCRIPTION и ChangeLog.md
```ShellSession
$ touch DESCRIPTION && edit DESCRIPTION #создание и редактирование файла DESCRIPTION
$ touch ChangeLog.md #создание файла ChangeLog
$ export DATE="`LANG=en_US date +'%a %b %d %Y'`" #добавление даты, юзернейма и электронной почты
$ cat > ChangeLog.md <<EOF
* ${DATE} ${GITHUB_USERNAME} <${GITHUB_EMAIL}> 0.1.0.0
- Initial RPM release
EOF
```
Редактирование файла CPackConfig.cmake
```ShellSession
$ cat > CPackConfig.cmake <<EOF
include(InstallRequiredSystemLibraries)
EOF
```
Устанавливаем значения 
```ShellSession
$ cat >> CPackConfig.cmake <<EOF
set(CPACK_PACKAGE_CONTACT ${GITHUB_EMAIL})  #электронная почта
set(CPACK_PACKAGE_VERSION_MAJOR \${PRINT_VERSION_MAJOR}) #версия MAJOR
set(CPACK_PACKAGE_VERSION_MINOR \${PRINT_VERSION_MINOR}) #версия MINOR
set(CPACK_PACKAGE_VERSION_PATCH \${PRINT_VERSION_PATCH}) #версия PATCH
set(CPACK_PACKAGE_VERSION_TWEAK \${PRINT_VERSION_TWEAK}) #версия TWEAK
set(CPACK_PACKAGE_VERSION \${PRINT_VERSION}) #версия печати на экран
set(CPACK_PACKAGE_DESCRIPTION_FILE \${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION)  #путь к файлу DESCRIPTION
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static c++ library for printing") #комментарий
EOF
```
Задаем пути к файлам
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RESOURCE_FILE_LICENSE \${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README \${CMAKE_CURRENT_SOURCE_DIR}/README.md)
EOF
```
Задаем параметры
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RPM_PACKAGE_NAME "print-devel") #имя пакета "print-devel"
set(CPACK_RPM_PACKAGE_LICENSE "MIT") #лицензия MIT
set(CPACK_RPM_PACKAGE_GROUP "print") #группа print
set(CPACK_RPM_PACKAGE_URL "https://github.com/${GITHUB_USERNAME}/lab07") #страница doxygen
set(CPACK_RPM_CHANGELOG_FILE \${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog.md) #путь к лог
set(CPACK_RPM_PACKAGE_RELEASE 1) #релиз истина 
EOF
```

```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_DEBIAN_PACKAGE_NAME "libprint-dev") #имя пакета"libprint-dev"
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://${GITHUB_USERNAME}.github.io/lab07") #домашняя страница doxygen
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.0") #версия cmake 3.0 и новее
set(CPACK_DEBIAN_PACKAGE_RELEASE 1) #релиз Debian истина
EOF
```
Подключаем cpack
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

include(CPack)
EOF
```
Подключаем CPackConfig.cmake
```ShellSession
$ cat >> CMakeLists.txt <<EOF

include(CPackConfig.cmake)
EOF
```

```ShellSession
$ gsed -i 's/lab07/lab08/g' README.md
```
Коммитим и пушим изменения в репозиторий
```ShellSession
$ git add .
$ git commit -m"added cpack config"
$ git push origin master
```
Активируем этот проект в Travis
```ShellSession
$ travis login --auto
$ travis enable
```
Сборка проекта
```ShellSession
$ cmake -H. -B_build 
$ cmake --build _build 
$ cd _build
$ cpack -G "TGZ"
$ cpack -G "RPM"
$ cpack -G "DEB"
$ cpack -G "NSIS"
$ cpack -G "DragNDrop"
$ cd ..
```
Архивируем проект
```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"  #задаем архивирование - TGZ
$ cmake --build _build --target package #архивирование
```
Создаем директорию artifacts и перемещаем в неё архивированный файл
```ShellSession
$ mkdir artifacts
$ mv _build/*.tar.gz artifacts
$ tree artifacts
artifacts
└── print-0.1.0.0-Darwin.tar.gz
```

## Report

```ShellSession
$ popd
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [DMG](https://cmake.org/cmake/help/latest/module/CPackDMG.html)
- [DEB](https://cmake.org/cmake/help/latest/module/CPackDeb.html)
- [RPM](https://cmake.org/cmake/help/latest/module/CPackRPM.html)
- [NSIS](https://cmake.org/cmake/help/latest/module/CPackNSIS.html)

```
Copyright (c) 2017 Братья Вершинины
```