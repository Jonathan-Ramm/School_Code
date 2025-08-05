% Überprüft, ob eine gegebene Kombination von Schalterstellungen die Bombe entschärft
loesung(A, B, C, D, E, F, G) :-
    % Überprüfe alle Regeln
    not((C = true, B = false, D = false)),  % Regel I
    not((A = false, D = false, G = true)),  % Regel II
    not((A = false, C = false, D = false)),  % Regel III
    not((F = false, B = true, C = true)),  % Regel IV
    not((D = true, C = true)),  % Regel V
    not((F = true, G = true, A = true)),  % Regel VI
    not((A = true, E = true, G = false)),  % Regel VII
    not((C = false, D = true, E = true)),  % Regel VIII
    not((A = true, G = true)),  % Regel IX
    not((E = false, B = true, F = true, C = true)),  % Regel X
    not((G = false, (C = true ; D = true))),  % Regel XI
    not((F \= G)),  % Regel XII
    not((B = false, C = false, E = false)),  % Regel XIII
    not((A = true, B = true, E = false, G = false)),  % Regel XIV
    not((F = false, G = false)).  % Regel XV

% Alle möglichen Kombinationen der Schalterstellungen (true oder false)
alle_kombinationen :-
    member(A, [true, false]),
    member(B, [true, false]),
    member(C, [true, false]),
    member(D, [true, false]),
    member(E, [true, false]),
    member(F, [true, false]),
    member(G, [true, false]),
    loesung(A, B, C, D, E, F, G),
    % Ausgabe der gültigen Kombination
    write([A, B, C, D, E, F, G]), nl,
    fail.  % Fortfahren, um alle Kombinationen zu überprüfen

% Um die Kombinationen zu sehen, rufen wir alle_kombinationen/0 auf

