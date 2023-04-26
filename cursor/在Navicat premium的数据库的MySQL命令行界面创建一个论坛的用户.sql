在Navicat premium的数据库的MySQL命令行界面创建一个论坛的用户表，类别表，帖子表，点赞表，收藏表。

CREATE TABLE users (
  id INT PRIMARY KEY,
  user_name VARCHAR(50) not null default '',
  pass_word VARCHAR(50) not null default '',
  nick_name VARCHAR(50) not null default '',
  email VARCHAR(50) not null default ''
);

INSERT INTO users (user_name, pass_word, nick_name, email)
VALUES ('new_user', 'password123', 'New User', 'new_user@example.com');

CREATE TABLE categories (
  id INT PRIMARY KEY,
  name VARCHAR(50)
);

INSERT INTO categories (name)
VALUES ('Category 1');

CREATE TABLE posts (
  id INT PRIMARY KEY,
  title VARCHAR(50),
  content TEXT,
  create_time VARCHAR(50),
  user_id INT,
  category_id INT,
  view_count INT,
  reply_count INT,
  FOREIGN KEY (user_id) REFERENCES users(id),
  FOREIGN KEY (category_id) REFERENCES categories(id)
);

INSERT INTO posts (title, content, user_id, category_id)
VALUES ('Post 1', 'This is the content of Post 1', 0, 0);

CREATE TABLE likes (
  id INT PRIMARY KEY,
  post_id INT,
  user_id INT,
  FOREIGN KEY (post_id) REFERENCES posts(id),
  FOREIGN KEY (user_id) REFERENCES users(id)
);

INSERT INTO likes (post_id, user_id)
VALUES (0, 0);

CREATE TABLE favorites (
  id INT PRIMARY KEY,
  post_id INT,
  user_id INT,
  add_time VARCHAR(50),
  FOREIGN KEY (post_id) REFERENCES posts(id),
  FOREIGN KEY (user_id) REFERENCES users(id)
);

INSERT INTO favorites (post_id, user_id,add_time)
VALUES (0, 0,2023/4/16);

UPDATE users
SET nick_name = 'New Nickname'
WHERE id = 1;