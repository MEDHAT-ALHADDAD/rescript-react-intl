type t = {
  id: string,
  defaultMessage: string,
  message: Js.nullable(string),
};

let toDict = (translations: array(t)) => {
  translations->Belt.Array.reduce(
    Js.Dict.empty(),
    (dict, entry) => {
      dict->Js.Dict.set(
        entry.id,
        switch (entry.message->Js.Nullable.toOption) {
        | None
        | Some("") => entry.defaultMessage
        | Some(message) => message
        },
      );
      dict;
    },
  );
};
