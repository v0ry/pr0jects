\title{
Datenstrukturen und Algorithmen, WS2024, Übungsblatt 2
}

Abzugeben bis siehe TC.

\section*{Rekursive Laufzeitfunktionen}

\section*{Hausaufgaben}

Aufgabe 1 (4 Points). Compute a tight asymptotic upper bound for \(T(n)=7 T(n / 2)+n^{2}\). The base case is \(n<2\) : \(T(n)=1\).

Aufgabe 2 (4 Points). Let \(T(n)=1\) for \(n \leq 2\). For \(n>2\), we have: \(T(n)=\sqrt{n} T(\sqrt{n})+n\). Show that \(T(n) \in\) \(\mathcal{O}(n \log \log n)\).
Hint: First, consider \(T^{\prime}(n)=\frac{T(n)}{n}\), from which \(T^{\prime}(\sqrt{n})=\frac{T(\sqrt{n})}{\sqrt{n}}\) can be derived.

Aufgabe 3 (4 Points). Compute a tight asymptotic upper bound for the following recursive function \(T(n)=T(\sqrt{n})+\) \(\log _{2} \log _{2} n\). Assume that \(T(n)=1\) for \(n \leq 2\).
Hint: Use the substitution \(m=\log _{2} n\), similar to the in-class exercise.
