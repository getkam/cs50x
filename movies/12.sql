SELECT m.title FROM movies m WHERE m.id IN(
SELECT s.movie_id FROM people p  JOIN stars s ON s.person_id = p.id WHERE p.name = "Bradley Cooper"
INTERSECT
SELECT s.movie_id FROM people p  JOIN stars s ON s.person_id = p.id WHERE p.name = "Jennifer Lawrence");
