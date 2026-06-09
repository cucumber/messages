export type NewId = () => string

export function uuid(): NewId {
  return () => crypto.randomUUID()
}

export function incrementing(): NewId {
  let next = 0
  return () => (next++).toString()
}
