const express = require('express');
const cookieParser = require('cookie-parser');
const path = require('path');
const { users } = require('./users'); // Usuários fixos

const app = express();
const PORT = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

const authCookieName = 'auth';

app.get('/', (req, res) => {
  const auth = req.cookies[authCookieName];
  if (auth) {
    const user = users.find(u => u.login === auth);
    if (user) {
      return res.send(`Bem vindo, ${user.nome}. Aqui estão suas informações restritas [...] <br><a href="/logout">Logout</a>`);
    }
  }
  res.sendFile(path.join(__dirname, 'login.html'));
});

app.post('/login', (req, res) => {
  const { login, senha, manterConectado } = req.body;
  const user = users.find(u => u.login === login && u.senha === senha);
  if (user) {
    if (manterConectado) {
      res.cookie(authCookieName, user.login, { maxAge: 3 * 24 * 60 * 60 * 1000 }); // 3 dias
    } else {
      res.cookie(authCookieName, user.login);
    }
    res.redirect('/');
  } else {
    res.send('Credenciais inválidas. <a href="/">Tente novamente</a>');
  }
});

app.get('/logout', (req, res) => {
  res.clearCookie(authCookieName);
  res.redirect('/');
});

app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});
