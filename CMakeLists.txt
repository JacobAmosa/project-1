cmake_minimum_required(VERSION 3.16.3)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project_1
        main.cpp
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        Token.cpp
        Token.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QmarkAutomaton.cpp
        QmarkAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        IdAutomaton.cpp
        IdAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        BadCommentAutomaton.cpp
        BadCommentAutomaton.h
        BadStringAutomaton.cpp
        BadStringAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Predicate.cpp Predicate.h Rule.cpp Rule.h Parameter.cpp Parameter.h Interpreter.cpp Interpreter.h Relation.cpp Relation.h Tuple.cpp Tuple.h Header.cpp Header.h Database.cpp Database.h)