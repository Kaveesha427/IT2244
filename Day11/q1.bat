

cd %USERPROFILE%\Desktop

mkdir CSC2244 Marks Exam
cd CSC2244
mkdir practical theory "exam papers"

cd practical

echo. > practical.docx
echo. > practical.txt
echo. > practical.pptx

cd..\theory
echo Theory Text > theory.txt
echo. > theory.docx
echo. > theory.pptx

cd "..\exam papers"
echo Exam Text > exam.txt
echo. > exam.docx
echo. > exam.pptx

cd %USERPROFILE%\Desktop

echo. > "Icae Marks.xlsx"
echo. > "Final Exam Marks.xlsx"

move "Icae Marks.xlsx" Marks
move "Final Exam.xlsx" Marks

xcopy /E /I Marks Exam\Marks
attrib +h Exam
