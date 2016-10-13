\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{USUexam}[2010/08/18 Class for USU exams]

\LoadClass{article}
\RequirePackage{fancyhdr}
\RequirePackage{lastpage}
\setlength{\headheight}{15.2pt}

\newcounter{question}
\newcounter{answerchoice}[question]
\setcounter{question}{1}

\newcommand{\setheader}[3]
{
\title{#1 ---  #2 \\ #3}
\author{Instructor: Dr. Kenneth Sundberg}

\lfoot{#1}
\rfoot{#2}
\cfoot{\thepage\ of \pageref{LastPage}}

%\rhead{Name: \hspace{1.5in}}
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
\LARGE
\begin{itemize}
\item You are permitted \textbf{one} page of notes
\item Limit your answers to the space provided
\item Make certain that your answers are legible
\item Remove this cover sheet and use it to cover your answers
\item You are responsible for keeping your answers hidden
\item Write your name on the \textbf{back} of every page
\item Be sure to complete all pages

\end{itemize}
\normalsize

\newpage

\newpage
}

\newenvironment{multiplechoice}[2]
{
%\begin{minipage}[h!]{.9\textwidth}
\setcounter{answerchoice}{0}
\textbf{\arabic{question})} #2 

\hfill #1 points
\addtocounter{question}{1}
}
{
%\end{minipage}
\vspace*{.25in}
}

\newcommand{\option}[1]
{

\addtocounter{answerchoice}{1}
(\Alph{answerchoice}) #1
}

\newcommand{\programming}[2]
{
\newpage
\parbox{.9\textwidth}
{
\textbf{\arabic{question})} #2 

\hfill #1 points

\vspace{.15cm}
\begin{center}
\framebox
{
\parbox{.8\textwidth}
{
\hspace{.3\textwidth}
\vspace*{6.25in}
}
}
\end{center}
}
\newpage
\addtocounter{question}{1}
}

\newcommand{\longanswer}[2]
{
\parbox{.9\textwidth}
{
\textbf{\arabic{question})} #2 

\hfill #1 points

\vspace{.15cm}
\begin{center}
\framebox
{
\parbox{.8\textwidth}
{
\hspace{.3\textwidth}
\vspace*{4.25in}
}
}
\end{center}
}
\newpage
\addtocounter{question}{1}
}


\newcommand{\shortanswer}[2]
{
\parbox{.9\textwidth}
{
\textbf{\arabic{question})} #2 

\hfill #1 points

\vspace{.25cm}
\begin{center}
\framebox
{
\parbox{.8\textwidth}
{
\hspace{.3\textwidth}
\vspace*{1.5in}
}
}
\end{center}
}
\vspace{.25cm}

\addtocounter{question}{1}
}