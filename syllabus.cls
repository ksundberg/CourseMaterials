\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{syllabus}[2010/08/18 Syllabus for USU CS class]

\LoadClass{article}
\RequirePackage{fancyhdr}
\RequirePackage{hyperref}

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
\section*{Add Policy}
The last day to add or drop this course without a notation is #1.
The last day to add this class is #1.
Attending this class beyond that date, without being officially registered, will not be approved by the Dean's Office.
Students must be officially registered for this course.
No assignments or tests of any kind will be graded for students whose names do not appear on the class list.

\section*{Drop Policy}
The last day to drop this class without notation is #1.
}

\newcommand{\officehours}[1]
{
\section*{Office Hours}
\begin{tabular}{ll}
Office Hours: & #1 \\
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
\section*{Students with Disabilities}
The Americans with Disabilities Act states: "Reasonable accommodation will be provided for all persons with disabiliteis in order to ensure equal participation within the program".
If a student has a disability that will likely require some accommodation by the instructor, the student must contact the instructor and document the disability through the Disability Resource Center (797-2444), preferably during the first week of the course.
Any request for special consideration relating to attendance, pedagogy, taking of examinations, etc., must be discussed with and approved by the instructor.
In cooperation with the Disability Resource Center, course materials can be provided in alternative format, large print, audio, diskette, or Braille. 

\section*{Sexual Harassment}
Sexual harassment is defined by the Affirmative Action/Equal Employement Opportunity Commission as any "unwelcom sexual advances, requests for sexual favors, and other verbal or physical conduct of a sexual nature". If you feel you are a victim of sexual harassment, you may talk to or file a complaint with the Affirmative Action/Equal Employment Opportunity Office located in Old Main, Room 161, or call the AA/EEO Office at 797-1266.

\section*{Academic Freedom and Professional Responsibilities}
Academic freedom is the right to teach, study, discuss, investigate, discover, create, and publish freely.
Academic freedom protects the rights of faculty members in teaching and of students in learning.
Freedom in research is fundamental to the advancement of truth.
Faculty members are entitled to full freedom in teaching, research, and creative activities, subject to the limitations imposed by professional responsibility.
Faculty Code Policy 403 further defines academic freedom and professional responsibilites.

\section*{Greivance Process}
Students who feel they have been unfairly treated [in matters other than (i) discipline or (ii) admission, residency, employment, traffic, and parking - which are addressed by procedures separate and independent from the Student Code] may file a frievance through the channels and procedures described in the Student Code: Aticle VII Grievances.
}

\newcommand{\cheating}
{
\section*{Cheating}
All forms fo cheating are absolutely prohibited.
Please read the department's policy (\url{https://digital.cs.usu.edu/cheating_policy.html})

\section*{Academic Integrity - "The Honor System"}
Each student has the right and duty to pursue his or her academic experience free of dishonesty.
The Honor System is designed to establish the higher level of conduct expected and required of all Utah State University students.

The Honor Pledge: To enhance the learning enviornment at Utah State University and to develop student academic integrity, each student agrees to the following Honor Pledge: "I pledge, on my honor, to conduct myself with the formost level of academic integrity."
A student who lives by the Honor Pledge is a student who does more than not cheat, falsify, or plagiarize.
A student who lives by the Honor Pledge:
\begin{itemize}
\item Espouses academic integrity as an underlying and essential principle of the Utah State University community;
\item Understands that each act of academic dishonesty devalues every degree that is awarded by this institution; and
\item Is a welcomed and valued member of Utah State University.
\end{itemize}

\section*{Plagiarism}
Plagiarism includes knowingly "representing, by paraphrase or direct quotation, the published or unpublished work of another person as one's own in any academic exercise or activity without full and clear acknowledgement.
It also includes the unacknowledged use of materials prepared by another person or agency engaged in the selling of term papers or other academic materials."
The penalties for plagiarism are severe.
The inluce warning or reprimand, grade adjustment, probation, suspension, expulsion, withholding of transcripts, denial or revocation of degrees, and referral to psychological counseling.
 
}

\newcommand{\nofees}
{
\section*{Class Fees}
There are no fees associated with this class.
}

\newcommand{\learningaids}
{
\section*{Learning Aids}
Lecture notes and other useful information will be available in electronic form on the class's section of the Canvas system.
Please check the class's news and notes sections on a regular basis.

The Computer Science Department is a member of the Microsoft's DreamSpark program.
Through this program, students in CS courses can obtain and use a number of Microsoft's operating and software packages.
If you are interested in downloading any of this software for your use, please follow the directions found on the department's website.
}

\newcommand{\withdrawal}
{
\section*{Withdrawl and Incomplete Grade Policy}
Students are required to complete all courses for which they are registered by the end of the semester.
In some cases, a student may be unable to complete all of the coursework because of extenuating circumstances, but not due to poor performace or to retain financial aid.  The term 'extenuating' circumstances includes:
\begin{enumerate}
\item incapacitating illness which prevents a student from attending classes for a minimum period of two weeks.
\item a death in the immediate family
\item financial responsibilities requireing a student to alter a work schedule to secure employment
\item change in work schedule as required by an employer
\item other emergencies deemed appropriate by the instructor
\end{enumerate}
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
