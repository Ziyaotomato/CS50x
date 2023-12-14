--1
SELECT title FROM movies WHERE year = 2008;
--2
SELECT birth FROM people WHERE name = 'Emma Stone';
--3
SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC;
--4
SELECT COUNT(movie_id) FROM ratings WHERE rating = 10;
--5
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year ASC;
--6
SELECT AVG(rating) FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE movies.year = 2012;
--7
SELECT title, rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title;
--8
SELECT people.name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id WHERE movies.title = 'Toy Story';
--9
SELECT people.name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id WHERE movies.year = 2004 ORDER BY people.birth;
--10
SELECT people.name FROM people JOIN directors ON people.id = directors.person_id JOIN movies ON movies.id = directors.movie_id JOIN ratings ON movies.id = ratings.movie_id WHERE rating >= 9.0;
--11
SELECT title FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id JOIN ratings ON movies.id = ratings.movie_id WHERE people.name = 'Chadwick Boseman' ORDER BY rating DESC LIMIT 5;
--12
SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Johnny Depp" AND movies.title IN( SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Helena Bonham Carter");
--13
SELECT DISTINCT(people.name) FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id WHERE movies.id IN (SELECT movies.id FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON people.id = stars.person_id WHERE people.name = 'Kevin Bacon' AND people.birth = 1958) AND people.name != 'Kevin Bacon';
