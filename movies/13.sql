SELECT s.movie_id FROM stars s JOIN people p ON s.person_id = p.id WHERE p.name = "Kevin Bacon" AND p.birth = 1958;
