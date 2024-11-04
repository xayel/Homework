# 定义编译器
CXX = g++
# 定义PDF生成器
PDF_COMPILER = pdflatex

# 定义程序的源文件
PROGRAM_SRC = test_BST.cpp

# 定义程序的可执行文件
PROGRAM_EXE = test_BST

# 默认目标
all: run

# 编译程序并运行
run:
	$(CXX) $(PROGRAM_SRC) -o $(PROGRAM_EXE)
	./$(PROGRAM_EXE)

# 清理编译生成的文件
clean:
	rm -f $(PROGRAM_EXE) $(REPORT_PDF) *.aux *.log *.out

report:  
	xelatex report.tex  