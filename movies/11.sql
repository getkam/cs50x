SELECT
  m.title
FROM
  movies m
  JOIN ratings r ON m.id = r.movie_id
WHERE
  m.id IN (
   SELECT
     s.id
   FROM
     starts s
     JOIN people p ON s.person_id = p.id
     WHERE
       name = "Chadwick Boseman")
ORDER BY r.rating DESC
LIMIT 5;

SELECT m.title FROM movies m JOIN ratings r ON m.id = r.movie_id WHERE m.id IN (SELECT s.id FROM starts s JOIN people p ON s.person_id = p.id WHERE name = "Chadwick Boseman") ORDER BY r.rating DESC LIMIT 5;
