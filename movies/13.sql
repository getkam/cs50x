SELECT DISTINCT(pp.name) FROM people pp JOIN stars ss ON pp.id = ss.person_id WHERE ss.movie_id IN (
SELECT s.movie_id FROM stars s JOIN people p ON s.person_id = p.id WHERE p.name = "Kevin Bacon" AND p.birth = 1958)
AND pp.id NOT IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958);

