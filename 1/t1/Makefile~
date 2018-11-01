.PHONY: all clean install help uninstall start dist doc cleanALL

PROG = filter
DIR = ~/bin
HEADERS = bmp.h filter.h
SOURCES = filter.c bmp_io.c bmp_gray.c bmp_filter.c
OBJECTS = $(SOURCES:.c=.o)

all: $(PROG)
$(PROG): $(OBJECTS)
filter.o bmp_gray.o bmp_filter.o bmp_io.o: bmp.h

#создание документации
doc:
	cat doc1 doc2 > manual
#тестовый запуск
start:
	./$(PROG) petrsu-logo.bmp res.bmp
	@echo "Test run successful"
#установка скомпилированного проекта
install:
	install ./$(PROG) $(DIR)
#создание сжатого архива
dist:
	tar -cvzf $(PROG).tar.gz $(SOURCES) $(HEADERS) Makefile help doc1 doc2
#справка об использовании файла сборки
help:
	cat help
#очистка проекта (без удаления некоторых файлов)
#rf удалит все файлы и каталоги в выбранном вами месте и ничего не напечатает
clean:
	rm -rf $(OBJECTS)
#полная очистка (приведение к исходному состоянию)
cleanALL:
	rm -rf $(OBJECTS) $(PROG) manual $(PROG) $(PROG).tar.gz err res.bmp
#подсчёт количества строк в файлах, содержащих код проекта
count:
	@echo "Number of lines in Sourses and Headers:"
	@wc -l $(SOURCES) $(HEADERS)
#справка в случае неправильно заданной цели
make: 
%::
	@cat help
