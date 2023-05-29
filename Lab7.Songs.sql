--1 
SELECT name FROM songs;
--2
SELECT name FROM songs ORDER BY tempo ASC;
--3
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;
--4
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;
--5
SELECT AVG(energy) FROM songs;
--6
SELECT AVG(energy) FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Drake';
--7
SELECT AVG(energy) FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Drake';
--8
SELECT name FROM songs WHERE name LIKE '%feat.%';
