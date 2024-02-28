SELECT
  m.title
FROM
  movies m
  JOIN ratings r ON m.id = r.movie_id
WHERE
  m.id IN (
   SELECT
     s.movie_id
   FROM
     stars s
     JOIN people p ON s.person_id = p.id
     WHERE
       p.name = "Chadwick Boseman")
ORDER BY r.rating DESC
LIMIT 5;
