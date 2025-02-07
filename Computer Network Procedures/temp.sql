CREATE TABLE course (
    e
);

CREATE TABLE student (
    ID NUMBER(10) PRIMARY KEY,
    name VARCHAR2(30),
    dept_name VARCHAR2(30) REFERENCES department(dept_name),
    tot_cred VARCHAR2(10)
);

CREATE TABLE advisor (
    s_id NUMBER(10) REFERENCES student(ID),
    i_id NUMBER(10) REFERENCES student(ID)
);
