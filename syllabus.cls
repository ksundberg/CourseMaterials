\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{syllabus}[2010/08/18 Syllabus for USU CS class]

\LoadClass{article}
\RequirePackage{fancyhdr}

\newcommand{\setheader}[2]
{
\title{#1 ---  #2}
\author{Instructor: Dr. Kenneth Sundberg}
\date{}

\lfoot{#1}
\rfoot{#2}
}

\AtEndOfClass
{
\renewcommand{\footrulewidth}{1pt}
}

\AtBeginDocument
{
\pagestyle{fancyplain}
\maketitle
\hrule
}

\newenvironment{text}[1]
{
\section*{Text}
The text for this course is \emph{#1}.
You are expected to read the chapter sections being covered in full.
The following topics will be covered:
\begin{center}
\begin{tabular}{lc}
& Chapter \\
}
{
\end{tabular}
\end{center}
}

\newcommand{\textchapter}[2]
{
#1 & #2\\
}

\newcommand{\finalexam}[1]
{
\section*{Final Exam}
The final exam for this course will be given on #1.
}

\newcommand{\adddrop}[1]
{
\section*{Add/Drop Date}
The last day to add or drop this course without a notation is #1.
}

\newcommand{\officehours}[1]
{
\section*{Office Hours}
\begin{tabular}{ll}
Office Hours: & By appointment only. \\
E-mail: & kasundberg@gmail.com \\
Phone: & 713-3487 \\
\end{tabular}

\vspace{1em}

Email is an excellent way to have questions resolved, as it requires you to clearly define your problem.  Also, the lab tutor rooms are an excellent resource.
You are expected to take advantage of them.
}

\newenvironment{grading}
{
\section*{Grading}
You are expected to attend each class and complete each assignment on time.
The final grades will be curved.
Grades will be based on the following:
\begin{center}
\begin{tabular}{lr}

}
{
\end{tabular}
\end{center}

\section*{Late Policy}
Assignments should be submitted on the day assigned.
Late work is marked down 10\% points per day late.
Work more than \textbf{3 days} late will not be accepted.
No special projects or extra credit work will be given to make up a low grade.
If your assignment consists of more than one file please submit a .zip file.

Please verify that all work is graded correctly and returned to you.
Keep all work until after the term has ended.
If you feel their has been an error in the grading please contact the instructor.
}



\newcommand{\gradecategory}[2]
{
#1 & #2\% \\
}

\newcommand{\ada}
{
\section*{ADA Compliance}
If a student has a disability that will likely require some accommodation by the instructor, the student must contact the instructor and document the disability through the Disability Resource Center, preferably during the first week of the course.  
Any requests for special considerations relating to attendance, pedagogy, taking of examinations, etc. must be discussed with and approved by the instructor.
In cooperation with the Disability Resource Center, course materials can be provided in alternative formats, e.g. large print, audio, diskette, or Braille.
}

\newcommand{\cheating}
{
\section*{Cheating}
Occurrences of cheating will have serious consequences for all those involved.
The first incident will carry a penalty of the student being given negative points equal to the value of the assignment quiz, etc. and a letter being sent to student services and his/her college.
 A second occurrence is grounds for a failing grade in the course and possible University action. Please refer to the Computer Science Department Bulletin Board for the department’s official policy.

Some examples of cheating include copying another’s work, turning in another’s work as your own, allowing someone else to copy your work, doing work for another, using unapproved materials during a test, and turning in duplicate or near-duplicate assignments.
You are responsible to protect your code. 
Take care to keep your code unavailable to other students. 
 
}

\newcommand{\fees}[1]
{
\section*{Class Fees}
Associated with this class is a class fee of \$#1.
The monies from this fee are used to maintain lab facilities for the class, purchase software and licenses, and supervise the lab.
In some cases, students may have their own computing equipment, and thus feel that they do not need to use the lab.
However, the lab must be maintained regardless of an individuals use of it, and thus the fee is charged to all registered for the class.
If you have questions or concerns about the fee, please see the department head.
}