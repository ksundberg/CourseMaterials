<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="text" omit-xml-declaration="yes"/>
  <xsl:template match="map/node">
\documentclass[usepdftitle=false,professionalfonts,compress]{beamer}
\usepackage[T1]{fontenc}
\usepackage{hyperref}
\usepackage{listings}
\usepackage{color}

\usetheme[]{Warsaw}
\beamertemplatenavigationsymbolsempty
\setbeamertemplate{footline}[frame number]

\title{<xsl:value-of select="@TEXT"/>}
\author{Kenneth Sundberg}
\subtitle{CS1400}
\date{}

\lstset{language=C++,
keywordstyle=\color{blue},
stringstyle=\color{red},
commentstyle=\color{green},
morecomment=[l][\color{magenta}]{\#}
}

\newcommand{\writeTextBookRefs}{}

\begin{document}
\frame[plain]{
\frametitle{}
\titlepage
}

<xsl:for-each select="node">
  \section{<xsl:value-of select="@TEXT"/>}
  <xsl:for-each select="node">
  \subsection{<xsl:value-of select="@TEXT"/>}
  <xsl:for-each select="node">
    <xsl:choose>
      <xsl:when test="@LOCALIZED_STYLE_REF='styles.important'">
\begin{frame}[fragile]
\frametitle{<xsl:value-of select="@TEXT"/>}
\begin{lstlisting}
<xsl:for-each select="node">
<xsl:value-of select="@TEXT"/>
<xsl:text>&#xa;</xsl:text>
</xsl:for-each>
\end{lstlisting}    
\end{frame}
      </xsl:when>
      <xsl:otherwise>
    \begin{frame}
    \frametitle{<xsl:value-of select="@TEXT"/>}
<xsl:for-each select="attribute">
      <xsl:if test="@NAME='textbook'">
\label{textbook:<xsl:value-of select="@VALUE"/>}
      </xsl:if>
      </xsl:for-each>
    <xsl:if test="node">
      \begin{itemize}
        <xsl:for-each select="node">
    \item <xsl:value-of select="@TEXT"/>
<xsl:if test="node">
      \begin{itemize}
  <xsl:for-each select="node">
    \item <xsl:value-of select="@TEXT"/>
      <xsl:if test="@LOCALIZED_STYLE_REF='styles.topic'">
        \pause
      </xsl:if>
</xsl:for-each>
      \end{itemize}
    </xsl:if>

      <xsl:if test="@LOCALIZED_STYLE_REF='styles.topic'">
        \pause
      </xsl:if>
</xsl:for-each>
      \end{itemize}
    </xsl:if>
    \end{frame}
  </xsl:otherwise>
  </xsl:choose>
</xsl:for-each>
</xsl:for-each>
</xsl:for-each>
\appendix
\begin{frame}
\frametitle{Textbook sections covered:}
\begin{itemize}
<xsl:for-each select="node/node/node/attribute">
<xsl:sort select="@VALUE"/>
<xsl:if test="position() mod 10 = 0">
\begin{frame}
\frametitle{Textbook sections covered:}
\begin{itemize}
</xsl:if>
\item Section <xsl:value-of select="@VALUE"/> (frame \ref{textbook:<xsl:value-of select="@VALUE"/>})
<xsl:if test="position() mod 10 = 9">
\end{itemize}
\end{frame}
</xsl:if>
<xsl:if test="position() mod 10 != 9">
<xsl:if test="position() = last()">
\end{itemize}
\end{frame}
</xsl:if>
</xsl:if>

</xsl:for-each>
\end{document}
  </xsl:template>
</xsl:stylesheet>
